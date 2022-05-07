using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyMove : MonoBehaviour
{
    Rigidbody2D rigid;
    Animator anim;
    SpriteRenderer spriteRenderer;
    public int nextMove;

    void Awake()
    {
        rigid = GetComponent<Rigidbody2D>();
        anim = GetComponent<Animator>();
        spriteRenderer = GetComponent<SpriteRenderer>();
        Think();
    }

    void FixedUpdate()
    {
        // 이동 구현
        rigid.velocity = new Vector2(nextMove, rigid.velocity.y);

        // 낭떠러지 구현
        Vector2 frontVec = new Vector2(rigid.position.x + nextMove, rigid.position.y);
        Debug.DrawRay(frontVec, Vector3.down, new Color(0, 1, 0));
        RaycastHit2D rayHit = Physics2D.Raycast(frontVec, Vector3.down, 1, LayerMask.GetMask("Ground"));
        if (rayHit.collider == null)
        {
            Turn();
        }
    }

    // 이동 재설정 구현
    void Think()
    {
        nextMove = Random.Range(-1, 2);

        // 이동 애니메이션 구현
        anim.SetInteger("WalkSpeed", nextMove);

        // 방향 전환 구현
        if (nextMove != 0) {
            spriteRenderer.flipX = nextMove == 1;
        }

        Invoke("Think", Random.Range(2f, 5f));
    }

    void Turn()
    {
        nextMove *= -1;
        spriteRenderer.flipX = nextMove == 1;
        CancelInvoke();
        Invoke("Think", Random.Range(2f, 5f));
    }
}